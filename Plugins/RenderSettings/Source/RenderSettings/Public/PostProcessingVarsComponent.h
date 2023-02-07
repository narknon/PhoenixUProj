#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarsComponentBase.h"
#include "PostProcessingVarsComponent.generated.h"

class UPostProcessingVar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API UPostProcessingVarsComponent : public UPostProcessingVarsComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPostProcessingVar*> Vars;
    
    UPostProcessingVarsComponent();
};

