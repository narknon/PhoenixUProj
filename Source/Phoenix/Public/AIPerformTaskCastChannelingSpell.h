#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskCastSpell.h"
#include "EPerformTasksChannelingSpell.h"
#include "AIPerformTaskCastChannelingSpell.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskCastChannelingSpell : public UAIPerformTaskCastSpell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTasksChannelingSpell ChannelingSpellType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldStopChannelingSpell;
    
    UAIPerformTaskCastChannelingSpell();
private:
    UFUNCTION(BlueprintCallable)
    void DisillusionmentFinished(uint8 InAction);
    
};

