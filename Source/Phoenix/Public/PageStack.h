#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PageStack.generated.h"

UCLASS(Blueprintable)
class UPageStack : public UObject {
    GENERATED_BODY()
public:
    UPageStack();
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable)
    void Push(const FString& Widget);
    
    UFUNCTION(BlueprintCallable)
    FString Pop();
    
    UFUNCTION(BlueprintCallable)
    FString Peek();
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetStack();
    
};

