#pragma once
#include "CoreMinimal.h"
#include "CollectedForageableDelegateDelegate.h"
#include "EForageableState.h"
#include "WorldObject.h"
#include "Foragable.generated.h"

UCLASS(Blueprintable)
class AForagable : public AWorldObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCollectedForageableDelegate OnForageableCollected;
    
    AForagable(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ResetState(EForageableState NextState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FName GetItemID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetItemCount() const;
    
};

