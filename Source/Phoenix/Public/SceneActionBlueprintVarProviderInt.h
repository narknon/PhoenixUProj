#pragma once
#include "CoreMinimal.h"
#include "SceneActionBlueprintVarProvider.h"
#include "SceneActionBlueprintVarProviderInt.generated.h"

class UIntProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneActionBlueprintVarProviderInt : public USceneActionBlueprintVarProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIntProvider* Value;
    
    USceneActionBlueprintVarProviderInt();
};

