#pragma once
#include "CoreMinimal.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_Socket.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_Socket : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UCogGroupTargetPoint_Socket();
};

