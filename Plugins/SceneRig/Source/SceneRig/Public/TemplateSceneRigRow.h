#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "TemplateSceneRigRow.generated.h"

class USceneRig;

USTRUCT(BlueprintType)
struct FTemplateSceneRigRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USceneRig> SceneRigClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* TemplateSceneRig;
    
    SCENERIG_API FTemplateSceneRigRow();
};

