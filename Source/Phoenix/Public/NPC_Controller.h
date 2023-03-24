#pragma once
#include "CoreMinimal.h"
#include "SocialAIController.h"
#include "NPC_Controller.generated.h"

class UBlackboardComponent;
class UCognitionComponent;

UCLASS(Blueprintable)
class PHOENIX_API ANPC_Controller : public ASocialAIController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionComponent* CognitionComponent;
    
    ANPC_Controller(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    UBlackboardComponent* GetBlackboard();
    
};

