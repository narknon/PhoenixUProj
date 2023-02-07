#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "SceneRigParameterBinding_Int.h"
#include "Int_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UInt_SceneRigParameter : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Int BoundParameter;
    
    UInt_SceneRigParameter();
};

