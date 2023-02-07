#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "AsyncWrapperChildReadyEventDelegate.h"
#include "AsyncWrapperClassLoadEventDelegate.h"
#include "AsyncLoadWrapper.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable, EditInlineNew)
class UAsyncLoadWrapper : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftClassPath ChildWidgetClassRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> CallbackParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsLoading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ClassIsLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ChildInstantiated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ChildInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAsyncWrapperClassLoadEvent OnChildLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAsyncWrapperChildReadyEvent OnChildReady;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* ChildWidgetInstance;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* LoadedChildClass;
    
public:
    UAsyncLoadWrapper();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetThrobberVisibility(ESlateVisibility NewVisibility);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetParent(UUserWidget* Parent);
    
    UFUNCTION(BlueprintCallable)
    void InstantiateChild();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitChild();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCanvasPanel* GetAttachCanvas();
    
public:
    UFUNCTION(BlueprintCallable)
    void AsyncLoadChildClass(bool InstantiateImmediately);
    
};

