#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "DbSingleColumnInfo.h"
#include "RootMotionModifierProperties_NPCStrafe.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_NPCStrafe : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> SubtypeIds;
    
    URootMotionModifierProperties_NPCStrafe();
};

