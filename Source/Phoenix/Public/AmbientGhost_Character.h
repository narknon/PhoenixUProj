#pragma once
#include "CoreMinimal.h"
#include "CustomizableCharacterInterface.h"
#include "GameFramework/Character.h"
#include "LODBudgeterInterface.h"
#include "SignificanceInterface.h"
#include "AmbientGhost_Character.generated.h"

class UAmbientGhost_AnimInstance;
class USplineComponent;

UCLASS(Blueprintable)
class AAmbientGhost_Character : public ACharacter, public ISignificanceInterface, public ILODBudgeterInterface, public ICustomizableCharacterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceAlongSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnToFacePlayerSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceAtWhichGhostFacesPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalDistanceAtWhichGhostFacesPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadiusVerticalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadiusVerticalDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAmbientGhost_AnimInstance> AmbientGhostAnimInstance;
    
    AAmbientGhost_Character(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedInnerRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredInnerRadius();
    
    
    // Fix for true pure virtual functions not being implemented
};

