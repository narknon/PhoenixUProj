#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "FXAutoTriggerCustomCompaninonBuilder.h"
#include "FXAutoTriggerCustomCompaninonBuilderNPC.generated.h"

class AActor;
class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerCustomCompaninonBuilderNPC : public UFXAutoTriggerCustomCompaninonBuilder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NPCKey;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NPCKeyName;
    
public:
    UFXAutoTriggerCustomCompaninonBuilderNPC();
};

