#pragma once
#include "CoreMinimal.h"
#include "EBreakableState.h"
#include "WorldObject.h"
#include "PersistentBreakable.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API APersistentBreakable : public AWorldObject {
    GENERATED_BODY()
public:
    APersistentBreakable(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ResetState(EBreakableState NextState);
    
};

