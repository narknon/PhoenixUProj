#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "AnimInstance_RetrieveActorTransform.generated.h"

UINTERFACE(Blueprintable)
class AVAANIMATION_API UAnimInstance_RetrieveActorTransform : public UInterface {
    GENERATED_BODY()
};

class AVAANIMATION_API IAnimInstance_RetrieveActorTransform : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool RetreiveComponentTransform(FTransform& TransformInWorldSpace);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AssignComponentTransform(const FTransform& TransformInWorldSpace);
    
};

