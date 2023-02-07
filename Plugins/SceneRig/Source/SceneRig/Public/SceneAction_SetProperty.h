#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneRigObjectActionBase_ComponentName.h"
#include "SetProperty_PropertyName.h"
#include "SceneAction_SetProperty.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SetProperty : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConstant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepStateOnCompletion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigObjectActionBase_ComponentName ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSetProperty_PropertyName PropertyName;
    
    USceneAction_SetProperty();
};

