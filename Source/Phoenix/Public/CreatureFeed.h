#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "CreatureFeed.generated.h"

class ACreature_Character;
class UCreatureFeedFloatingComponent;

UCLASS(Blueprintable)
class ACreatureFeed : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartFeedAnimDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePelletStartingScaleInAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWaitTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreatureFeedFloatingComponent* FeedFloatingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* SelectedCreature;
    
public:
    ACreatureFeed();
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStartedVanishing();
    
public:
    UFUNCTION(BlueprintCallable)
    void InitializeRelease(ACreature_Character* NewSelectedCreature);
    
    UFUNCTION(BlueprintCallable)
    void FloatToCreature(FVector ReleaseVelocity);
    
};

