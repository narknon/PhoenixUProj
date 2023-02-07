#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MastermindJsonObject.generated.h"

class UMastermindJsonObject;

UCLASS(Blueprintable)
class MASTERMIND_API UMastermindJsonObject : public UObject {
    GENERATED_BODY()
public:
    UMastermindJsonObject();
    UFUNCTION(BlueprintCallable)
    FString ToJsonString();
    
    UFUNCTION(BlueprintCallable)
    void SetStringListField(const FString& InKey, const TArray<FString>& InValues);
    
    UFUNCTION(BlueprintCallable)
    void SetStringField(const FString& InKey, const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetObjectListField(const FString& InKey, const TArray<UMastermindJsonObject*>& InValues);
    
    UFUNCTION(BlueprintCallable)
    void SetObjectField(const FString& InKey, const UMastermindJsonObject* InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetNumberListField(const FString& InKey, const TArray<float>& InValues);
    
    UFUNCTION(BlueprintCallable)
    void SetNumberField(const FString& InKey, float InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetNullField(const FString& InKey);
    
    UFUNCTION(BlueprintCallable)
    void SetBooleanListField(const FString& InKey, const TArray<bool>& InValues);
    
    UFUNCTION(BlueprintCallable)
    void SetBooleanField(const FString& InKey, bool InValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyFields() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetStringListFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    FString GetStringFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    TArray<UMastermindJsonObject*> GetObjectListFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    UMastermindJsonObject* GetObjectFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    TArray<float> GetNumberListFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    float GetNumberFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    TArray<bool> GetBooleanListFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
    UFUNCTION(BlueprintCallable)
    bool GetBooleanFieldOrDefault(const FString& InKey, bool& bOutHasField);
    
};

