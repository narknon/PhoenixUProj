#pragma once
#include "CoreMinimal.h"
#include "GameLogicComponent.h"
#include "InputContextWithType.h"
#include "InputFilter.h"
#include "ContextFilterComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CONTROLMAPPER_API UContextFilterComponent : public UGameLogicComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> StartingContexts;
    
    UContextFilterComponent();
    UFUNCTION(BlueprintCallable)
    static void SetContextOnActor(AActor* InActor, const FInputContextWithType Context, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetContext(const FInputContextWithType Context, bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveFilter(const FInputFilter& InFilter);
    
    UFUNCTION(BlueprintCallable)
    static bool GetContextOnActor(AActor* InActor, const FInputContextWithType Context);
    
    UFUNCTION(BlueprintCallable)
    bool GetContext(const FInputContextWithType Context);
    
    UFUNCTION(BlueprintCallable)
    static bool EvaluateFilterOnActor(AActor* InActor, const FInputFilter InputFilter);
    
    UFUNCTION(BlueprintCallable)
    bool EvaluateFilter(const FInputFilter& InFilter);
    
    UFUNCTION(BlueprintCallable)
    static void ClearContextOnActor(AActor* InActor, const FInputContextWithType Context);
    
    UFUNCTION(BlueprintCallable)
    void ClearContext(const FInputContextWithType Context);
    
    UFUNCTION(BlueprintCallable)
    void AddFilter(const FInputFilter& InFilter);
    
};

