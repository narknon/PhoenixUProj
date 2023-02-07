#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "ablRepresentInventoryItemTask.generated.h"

class AActor;
class AMunitionType_Base;
class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew)
class UablRepresentInventoryItemTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SpawnClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> TemplateClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionTemplateClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AlphaCurve;
    
public:
    UablRepresentInventoryItemTask();
};

