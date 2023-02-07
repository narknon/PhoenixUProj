#pragma once
#include "CoreMinimal.h"
#include "CogGroupFocusDirection.h"
#include "CogGroupFocusDirection_Socket.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupFocusDirection_Socket : public UCogGroupFocusDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UCogGroupFocusDirection_Socket();
};

