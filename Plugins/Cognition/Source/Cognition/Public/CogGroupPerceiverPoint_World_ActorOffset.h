#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CogGroupPerceiverPoint.h"
#include "CogGroupPerceiverPoint_World_ActorOffset.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupPerceiverPoint_World_ActorOffset : public UCogGroupPerceiverPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UCogGroupPerceiverPoint_World_ActorOffset();
};

