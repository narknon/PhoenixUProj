#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SocialJournalHeadlineWidget.generated.h"

class UImage;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class USocialJournalHeadlineWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Count;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Name;
    
    USocialJournalHeadlineWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable)
    void InitDetails(FText NewName, const FString& IconName, int32 NewCount);
    
};

