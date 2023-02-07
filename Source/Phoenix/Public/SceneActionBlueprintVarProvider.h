#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneActionBlueprintVarProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class USceneActionBlueprintVarProvider : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnce;
    
    USceneActionBlueprintVarProvider();
};

