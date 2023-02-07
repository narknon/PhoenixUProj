#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CogGroupLookAtPoint.h"
#include "CogGroupLookAtPoint_World_ActorOffset.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupLookAtPoint_World_ActorOffset : public UCogGroupLookAtPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UCogGroupLookAtPoint_World_ActorOffset();
};

