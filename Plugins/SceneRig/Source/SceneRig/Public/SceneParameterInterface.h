#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SceneParameterInterface.generated.h"

class UObject;
class USceneRigStageParameterBlock;

UINTERFACE(BlueprintType, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class USceneParameterInterface : public UInterface {
    GENERATED_BODY()
};

class ISceneParameterInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual USceneRigStageParameterBlock* CreateParameterBlock(UObject* OuterObject) PURE_VIRTUAL(CreateParameterBlock, return NULL;);
    
};

