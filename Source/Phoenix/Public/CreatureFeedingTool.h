#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "CreatureInteractionTool.h"
#include "CreatureFeedingTool.generated.h"

class ACreature_Character;

UCLASS(Blueprintable)
class ACreatureFeedingTool : public ACreatureInteractionTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PelletsCloseReleaseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PelletsCloseReleaseVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PelletsMediumReleaseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PelletsMediumReleaseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PelletsMediumReleaseVelocityMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PelletsMediumReleaseVelocityMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PelletsThrowReleaseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PelletsThrowReleaseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PelletsThrowReleaseVelocityMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PelletsThrowReleaseVelocityMax;
    
    ACreatureFeedingTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupDistanceBasedPelletReleaseAnim(ACreature_Character* InCreatureCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector CalculateDynamicPelletReleaseVeloctiy(ACreature_Character* InCreatureCharacter) const;
    
};

