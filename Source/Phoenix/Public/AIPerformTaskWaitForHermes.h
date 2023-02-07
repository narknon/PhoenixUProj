#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskWaitForHermes.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskWaitForHermes : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomHermesMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToPlayer;
    
    UAIPerformTaskWaitForHermes();
private:
    UFUNCTION(BlueprintCallable)
    void OnHermesMessageExecuted(const UObject* i_caller);
    
};

