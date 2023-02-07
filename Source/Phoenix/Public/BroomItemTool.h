#pragma once
#include "CoreMinimal.h"
#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"
#include "BroomItemTool.generated.h"

class AFlyingBroom;
class UAnimationArchitectAsset;

UCLASS(Blueprintable)
class ABroomItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlyingBroom> FlyingBroomClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFlyingBroom> FlyingBroomProp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedBoostUnavailableMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedBoostOnCooldownMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimationArchitectAsset> RiderAnimationSetArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationArchitectAsset* LoadedAnims;
    
public:
    ABroomItemTool();
    UFUNCTION(BlueprintCallable)
    void SpawnAndMountBroom(bool bUseTransition, bool bInDestroyAfterMount);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimsLoaded(bool bUseTransition);
    
    UFUNCTION(BlueprintCallable)
    void MountBroom(bool bUseTransition);
    
};

