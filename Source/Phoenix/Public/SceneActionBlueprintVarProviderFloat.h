#pragma once
#include "CoreMinimal.h"
#include "SceneActionBlueprintVarProvider.h"
#include "SceneActionBlueprintVarProviderFloat.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneActionBlueprintVarProviderFloat : public USceneActionBlueprintVarProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Value;
    
    USceneActionBlueprintVarProviderFloat();
};

