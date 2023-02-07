#pragma once
#include "CoreMinimal.h"
#include "CogGroupLookAtPoint.h"
#include "CogGroupLookAtPoint_Socket.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupLookAtPoint_Socket : public UCogGroupLookAtPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UCogGroupLookAtPoint_Socket();
};

