#pragma once
#include "CoreMinimal.h"
#include "HermesMessageAdvancedDynamicPayload.h"
#include "SceneAction_HermesMessageAdvanced.h"
#include "SceneAction_HermesMessageAdvancedStartEnd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_HermesMessageAdvancedStartEnd : public USceneAction_HermesMessageAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StartMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHermesMessageAdvancedDynamicPayload StartData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EndMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHermesMessageAdvancedDynamicPayload EndData;
    
    USceneAction_HermesMessageAdvancedStartEnd();
};

