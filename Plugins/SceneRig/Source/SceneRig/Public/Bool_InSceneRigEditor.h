#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_InSceneRigEditor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_InSceneRigEditor : public UBoolProvider {
    GENERATED_BODY()
public:
    UBool_InSceneRigEditor();
};

