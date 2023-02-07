#pragma once
#include "CoreMinimal.h"
#include "BrewingRecipe.h"
#include "EBrewingState.h"
#include "InteractiveObjectActor.h"
#include "BrewingSite.generated.h"

class ABrewingSite;
class UBrewingSiteState;
class UChildActorComponent;
class USkeletalMesh;

UCLASS(Blueprintable)
class ABrewingSite : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBrewingSiteBecomeInactiveDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBrewingSiteBecomeActiveDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBrewingSiteBecomeActiveDelegate BrewingSiteBecomeActiveDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBrewingSiteBecomeInactiveDelegate BrewingSiteBecomeInactiveDelegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABrewingSite* LeftNeighbor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABrewingSite* RightNeighbor;
    
public:
    ABrewingSite();
    UFUNCTION(BlueprintCallable)
    static void SetBrewingNeighborsFromChildComponents(const TArray<UChildActorComponent*>& ChildComponents, bool bLoopNeighbors);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OpenSiteUI();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USkeletalMesh* GetCauldronSkeletalMesh() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FName GetCauldronID() const;
    
    UFUNCTION(BlueprintCallable)
    UBrewingSiteState* GetBrewingSiteState();
    
    UFUNCTION(BlueprintCallable)
    void DestroyPotion(FName CollectorID);
    
    UFUNCTION(BlueprintCallable)
    void CollectPotion(FName CollectorID, bool& bOutCollectedAnything, int32& OutYieldLeft);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_NotifyBrewingStateChange(EBrewingState NewState, bool bIsInitialState);
    
public:
    UFUNCTION(BlueprintCallable)
    void BeginBrewingPotion(const FBrewingRecipe& BrewingRecipe);
    
};

