#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigStage_NamedParameter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigStage_NamedParameter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ParameterName;
    
    USceneRigStage_NamedParameter();
};

