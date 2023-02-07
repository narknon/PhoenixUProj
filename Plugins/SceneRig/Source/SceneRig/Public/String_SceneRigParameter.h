#pragma once
#include "CoreMinimal.h"
#include "StringProvider.h"
#include "SceneRigParameterBinding_FString.h"
#include "String_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UString_SceneRigParameter : public UStringProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_FString BoundParameter;
    
    UString_SceneRigParameter();
};

