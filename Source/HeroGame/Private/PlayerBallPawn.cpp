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
	
	if(CurrentBallMaterial == nullptr)
		SwitchMaterial(EBallMaterialType::Wood);

	//AActor::GetWorld()->GetFirstPlayerController()->Possess(this);
}

// Called every frame
void APlayerBallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerBallPawn::Roll(const FVector2d& inputAxis)
{
	const auto normalizedInput = inputAxis.GetSafeNormal();
	const auto cameraForwardVec = CameraSpringArmComponent->GetForwardVector();
	const auto cameraRightVec = CameraSpringArmComponent->GetRightVector();
	
	// Calculate torque based on camera rotation
	//const FVector Torque = FVector(CameraForwardVec.X * TargetRoll * -1,CameraForwardVec.Y * TargetRoll * -1,0.0);
	const FVector torque = FVector(normalizedInput.X * GetWorld()->DeltaTimeSeconds * 100000000000,
		normalizedInput.Y* GetWorld()->DeltaTimeSeconds * 100000000000,
		0);
	
	auto debugString =  FString::Printf(TEXT("X: %f, Y: %f"), torque.X, torque.Y);
	LogUtil::Log(debugString);
	
	BallComponent->AddTorqueInRadians(torque);
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

