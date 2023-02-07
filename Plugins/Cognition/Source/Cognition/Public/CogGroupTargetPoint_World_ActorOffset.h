#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_World_ActorOffset.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_World_ActorOffset : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UCogGroupTargetPoint_World_ActorOffset();
};

