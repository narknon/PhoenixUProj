#pragma once
#include "CoreMinimal.h"
#include "CogGroupUpDirection.h"
#include "CogGroupUpDirection_Socket.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupUpDirection_Socket : public UCogGroupUpDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UCogGroupUpDirection_Socket();
};

