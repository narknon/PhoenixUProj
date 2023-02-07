#pragma once
#include "CoreMinimal.h"
#include "CogGroupPerceiverPoint.h"
#include "CogGroupPerceiverPoint_Socket.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupPerceiverPoint_Socket : public UCogGroupPerceiverPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UCogGroupPerceiverPoint_Socket();
};

