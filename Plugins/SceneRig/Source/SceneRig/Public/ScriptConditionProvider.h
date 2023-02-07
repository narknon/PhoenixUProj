#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "ScriptConditionProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UScriptConditionProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UScriptConditionProvider();
};

