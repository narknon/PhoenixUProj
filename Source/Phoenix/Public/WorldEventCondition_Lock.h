#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_Lock.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_Lock : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo Lock;
    
    UWorldEventCondition_Lock();
};

