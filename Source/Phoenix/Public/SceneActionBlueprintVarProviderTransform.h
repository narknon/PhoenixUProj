#pragma once
#include "CoreMinimal.h"
#include "SceneActionBlueprintVarProvider.h"
#include "SceneActionBlueprintVarProviderTransform.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneActionBlueprintVarProviderTransform : public USceneActionBlueprintVarProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Value;
    
    USceneActionBlueprintVarProviderTransform();
};

