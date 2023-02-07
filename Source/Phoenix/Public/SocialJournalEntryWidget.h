#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SocialJournalEntryWidget.generated.h"

class UImage;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class USocialJournalEntryWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Count;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* IconObserver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* IconObserverType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* IconSource;
    
    USocialJournalEntryWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable)
    void InitDetails(const FString& inIconObserverName, const FString& inIconObserverTypeName, const FString& inIconSourceName, int32 InCount);
    
};

