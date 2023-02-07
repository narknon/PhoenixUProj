#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UMGFocusManager.generated.h"

class AUMGInputManager;

UCLASS(Blueprintable)
class UMGFOCUS_API UUMGFocusManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AUMGInputManager* UMGInputManager;
    
public:
    UUMGFocusManager();
};

