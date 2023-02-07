#pragma once
#include "CoreMinimal.h"
#include "SceneActionBlueprintVarProvider.h"
#include "SceneActionBlueprintVarProviderVector.generated.h"

class UVectorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneActionBlueprintVarProviderVector : public USceneActionBlueprintVarProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* Value;
    
    USceneActionBlueprintVarProviderVector();
};

