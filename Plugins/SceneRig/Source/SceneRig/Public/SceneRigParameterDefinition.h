#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigParameterDefinition.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SCENERIG_API USceneRigParameterDefinition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    USceneRigParameterDefinition();
};

