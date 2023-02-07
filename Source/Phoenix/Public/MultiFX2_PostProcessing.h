#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "EFXPostProcessingDuplicateAction.h"
#include "MultiFX2_PostProcessing.generated.h"

class UMultiFX2_PostProcessingDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_PostProcessing : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMultiFX2_PostProcessingDefinition* Definition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoBlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAutoBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAutoBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXPostProcessingDuplicateAction IfAlreadyRunning;
    
    UMultiFX2_PostProcessing();
};

