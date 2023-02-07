#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "CollectionsScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UCollectionsScreen : public UTabPageWidget {
    GENERATED_BODY()
public:
    UCollectionsScreen();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetUsedInRecipesForCollectionItem(FName CollectionItem, FName CollectionCategory, bool IncludeLocked);
    
};

