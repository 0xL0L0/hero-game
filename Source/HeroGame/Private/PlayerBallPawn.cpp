// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBallPawn.h"

#include "HeroGameInstance.h"
#include "LogUtil.h"
#include "GameFramework/PawnMovementComponent.h"
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
	BallCollisionComponent = Cast<USphereComponent>(GetDefaultSubobjectByName("PlayerBallCollision"));
	CameraSpringArmComponent = Cast<USpringArmComponent>(GetDefaultSubobjectByName("CameraSpringArm"));
	CameraComponent = Cast<UCameraComponent>(GetDefaultSubobjectByName("Camera"));
	
	if(CurrentBallMaterial == nullptr)
		SwitchMaterial(EBallMaterialType::Wood);

	//AActor::GetWorld()->GetFirstPlayerController()->Possess(this);

	// TODO - REMOVE MAGIC NUMBERS
	JumpCooldown = 0.1f;
}

// Called every frame
void APlayerBallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CameraFollowBall();
	CheckUpdateGrounding();
	ClampLinearVelocity();
	HandleTimers();
}

void APlayerBallPawn::HandleTimers()
{
	if(JumpCooldown <= 0)
	{
		return;
	}
	
	JumpCooldown -= GetWorld()->DeltaTimeSeconds;
}

void APlayerBallPawn::CheckUpdateGrounding()
{
	FVector StartLocation = BallComponent->GetComponentLocation();
	FVector EndLocation = StartLocation - FVector(0.0f, 0.0f, 15);
	FHitResult HitResult;
	
	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(BallCollisionComponent->GetScaledSphereRadius())
	);
	
	bIsGrounded = bHit;
}

void APlayerBallPawn::ClampLinearVelocity() const
{
	return;
	
	const FVector currentVelocity = BallCollisionComponent->GetPhysicsLinearVelocity();
	const FVector clampedVelocity = currentVelocity.GetClampedToMaxSize(CurrentBallMaterial->MaxLinearVelocity);
	BallCollisionComponent->SetPhysicsLinearVelocity(clampedVelocity);
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

	MovementDirection = (cameraForwardNorm * normalizedInput.X) + (cameraRightNorm * normalizedInput.Y);
	MovementDirection.Normalize();

	// Inputs are inverted because torque is applies on an axis of rotation, rather than a direction
	FVector torqueDirection = (cameraForwardNorm * (normalizedInput.Y * -1)) + (cameraRightNorm * normalizedInput.X);
	torqueDirection.Normalize();
	
	BallCollisionComponent->AddTorqueInDegrees(torqueDirection * CurrentBallMaterial->MovementRollForce * GetWorld()->GetDeltaSeconds() * 100000);
	
	if(!bIsGrounded)
	{
		const FVector Force = FVector(MovementDirection * CurrentBallMaterial->MovementAirControl);
		BallCollisionComponent->AddForce(Force,"None",false);
	}
}

void APlayerBallPawn::Jump()
{
	if(!bIsGrounded || JumpCooldown > 0)
	{
		return;
	}

	FVector currentLinearVelocity = BallCollisionComponent->GetPhysicsLinearVelocity("None");
	const FVector Impulse = FVector(0.0f, 0.0f, CurrentBallMaterial->MovementJumpForce);
	BallCollisionComponent->SetPhysicsLinearVelocity(FVector(currentLinearVelocity.X,currentLinearVelocity.Y,0));
	BallCollisionComponent->AddImpulse(Impulse);

	JumpCooldown = 0.1f;
}

void APlayerBallPawn::Dash(const FVector& direction)
{
	auto DashVelocity = direction * CurrentBallMaterial->MovementDashForce;
	BallCollisionComponent->SetPhysicsAngularVelocityInDegrees(FVector(0,0,0));
	BallCollisionComponent->SetPhysicsLinearVelocity(FVector(0,0,0));
	BallCollisionComponent->AddImpulse(DashVelocity);
}

void APlayerBallPawn::SwitchMaterial(const EBallMaterialType& materialType)
{
	CurrentBallMaterial = GameInstance->BallMaterialCollection->GetBallMaterial(materialType);
	
	BallComponent->SetMaterial(0,CurrentBallMaterial->BaseMaterial);
	BallCollisionComponent->SetPhysMaterialOverride(CurrentBallMaterial->PhysicalMaterial);
	BallCollisionComponent->SetMassOverrideInKg("None", CurrentBallMaterial->Mass);
	BallCollisionComponent->SetLinearDamping(CurrentBallMaterial->LinearDamping);
	BallCollisionComponent->SetAngularDamping(CurrentBallMaterial->AngularDamping);
	BallCollisionComponent->SetPhysicsMaxAngularVelocityInDegrees(CurrentBallMaterial->MaxAngularVelocity);
}

