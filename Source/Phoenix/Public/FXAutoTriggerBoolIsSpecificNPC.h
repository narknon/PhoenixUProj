#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolIsSpecificNPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolIsSpecificNPC : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NPCKey;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NPCKeyName;
    
public:
    UFXAutoTriggerBoolIsSpecificNPC();
};

