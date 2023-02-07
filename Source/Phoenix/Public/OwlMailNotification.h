#pragma once
#include "CoreMinimal.h"
#include "HUDElementGroup.h"
#include "OwlMailNotification.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UOwlMailNotification : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UOwlMailNotification();
    UFUNCTION(BlueprintCallable)
    int32 PlayMailDialogLine(const FString& MailID);
    
};

