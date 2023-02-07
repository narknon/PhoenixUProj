#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MorphTargetInterface.generated.h"

UINTERFACE(Blueprintable)
class UMorphTargetInterface : public UInterface {
    GENERATED_BODY()
};

class IMorphTargetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMorphTargetsReceived(const TMap<FName, float>& MorphTargets);
    
};

