// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBallPawn.h"

#include "HeroGameInstance.h"
#include "LogUtil.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerBallPawn::APlayerBallPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerBallPawn::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UHeroGameInstance>(GetGameInstance());
	GameMode = Cast<AHeroGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	BallComponent = Cast<UStaticMeshComponent>(GetDefaultSubobjectByName("PlayerBall"));
	CameraSpringArmComponent = Cast<USpringArmComponent>(GetDefaultSubobjectByName("CameraSpringArm"));
	CameraComponent = Cast<UCameraComponent>(GetDefaultSubobjectByName("Camera"));
	
	if(CurrentBallMaterial == nullptr)
		SwitchMaterial(EBallMaterialType::Wood);

	//AActor::GetWorld()->GetFirstPlayerController()->Possess(this);
}

// Called every frame
void APlayerBallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CameraFollowBall();
}

void APlayerBallPawn::CameraFollowBall()
{
	CameraSpringArmComponent->SetWorldLocation(BallComponent->GetComponentTransform().GetLocation());
}

void APlayerBallPawn::RotateCamera(const float axis)
{
	float rotation = CameraRotationSpeed * axis;
	FRotator rotator = FRotator(0,rotation,0);
	CameraSpringArmComponent->AddWorldRotation(rotator);
}

void APlayerBallPawn::Roll(const FVector2d& inputAxis)
{
	const auto normalizedInput = inputAxis.GetSafeNormal();
	const auto cameraForward = CameraComponent->GetForwardVector();
	const auto cameraRight = CameraComponent->GetRightVector();
	const auto cameraForwardNorm = FVector(cameraForward.X, cameraForward.Y, 0).GetSafeNormal();
	const auto cameraRightNorm = FVector(cameraRight.X, cameraRight.Y, 0).GetSafeNormal();

	FVector torque = (cameraForwardNorm * normalizedInput.Y) + (cameraRightNorm * normalizedInput.X);
	torque.Normalize();
	
	BallComponent->AddTorqueInRadians(torque * 1000000);
}

void APlayerBallPawn::SwitchMaterial(const EBallMaterialType& materialType)
{
	CurrentBallMaterial = GameInstance->BallMaterialCollection->GetBallMaterial(materialType);
	
	BallComponent->SetMaterial(0,CurrentBallMaterial->BaseMaterial);
	BallComponent->SetPhysMaterialOverride(CurrentBallMaterial->PhysicalMaterial);
	BallComponent->SetMassOverrideInKg("None", CurrentBallMaterial->Mass);
	BallComponent->SetLinearDamping(CurrentBallMaterial->LinearDamping);
	BallComponent->SetAngularDamping(CurrentBallMaterial->AngularDamping);
	BallComponent->SetPhysicsMaxAngularVelocityInDegrees(CurrentBallMaterial->MaxAngularVelocity);
}

