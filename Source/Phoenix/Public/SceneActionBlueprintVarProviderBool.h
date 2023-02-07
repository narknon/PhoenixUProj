#pragma once
#include "CoreMinimal.h"
#include "SceneActionBlueprintVarProvider.h"
#include "SceneActionBlueprintVarProviderBool.generated.h"

class UBoolProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneActionBlueprintVarProviderBool : public USceneActionBlueprintVarProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* Value;
    
    USceneActionBlueprintVarProviderBool();
};

