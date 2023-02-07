#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActivityTypeIDs.h"
#include "AmbientChatterTopicIDs.h"
#include "CollisionTypeIDs.h"
#include "HouseIds.h"
#include "PropClassIDs.h"
#include "PropTypeIDs.h"
#include "SkeletonTypeIDs.h"
#include "SocialActionObserverTypes.h"
#include "SocialActionTypes.h"
#include "SocialCapitalStatusIDs.h"
#include "SocialConnectionIDs.h"
#include "SocialHeritageStatusIDs.h"
#include "SocialInteractionDisplayStatusIDs.h"
#include "SocialInteractionTypeIDs.h"
#include "SocialSemanticIDs.h"
#include "SocialSemanticTypeIDs.h"
#include "UIActionModes.h"
#include "UIHUDGroups.h"
#include "SocialEnumsBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class USocialEnumsBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USocialEnumsBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static FName GetUIHUDGroupNameFromID(TEnumAsByte<UIHUDGroups> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<UIHUDGroups> GetUIHUDGroupFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetUIActionModeNameFromID(TEnumAsByte<UIActionModes> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<UIActionModes> GetUIActionModeFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialSemanticTypeIDNameFromID(TEnumAsByte<SocialSemanticTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialSemanticTypeIDs> GetSocialSemanticTypeIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialSemanticIDNameFromID(TEnumAsByte<SocialSemanticIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialSemanticIDs> GetSocialSemanticIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialInteractionTypeIDNameFromID(TEnumAsByte<SocialInteractionTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialInteractionTypeIDs> GetSocialInteractionTypeIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialInteractionDisplayStatusIDNameFromID(TEnumAsByte<SocialInteractionDisplayStatusIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialInteractionDisplayStatusIDs> GetSocialInteractionDisplayStatusIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialHeritageStatusIDNameFromID(TEnumAsByte<SocialHeritageStatusIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialHeritageStatusIDs> GetSocialHeritageStatusIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialConnectionIDNameFromID(TEnumAsByte<SocialConnectionIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialConnectionIDs> GetSocialConnectionIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialCapitalStatusIDNameFromID(TEnumAsByte<SocialCapitalStatusIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialCapitalStatusIDs> GetSocialCapitalStatusIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialActionTypeNameFromID(TEnumAsByte<SocialActionTypes> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialActionTypes> GetSocialActionTypeFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSocialActionObserverTypeNameFromID(TEnumAsByte<SocialActionObserverTypes> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SocialActionObserverTypes> GetSocialActionObserverTypeFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetSkeletonTypeIDNameFromID(TEnumAsByte<SkeletonTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<SkeletonTypeIDs> GetSkeletonTypeIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetPropTypeIDNameFromID(TEnumAsByte<PropTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<PropTypeIDs> GetPropTypeIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetPropClassIDNameFromID(TEnumAsByte<PropClassIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<PropClassIDs> GetPropClassIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetHouseNameFromRegistryID(const FString& InRegistryID);
    
    UFUNCTION(BlueprintCallable)
    static FName GetHouseIDNameFromID(TEnumAsByte<HouseIds> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<HouseIds> GetHouseIDFromRegistryID(const FString& InRegistryID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<HouseIds> GetHouseIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetCollisionTypeIDNameFromID(TEnumAsByte<CollisionTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<CollisionTypeIDs> GetCollisionTypeIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetAmbientChatterTopicIDNameFromID(TEnumAsByte<AmbientChatterTopicIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<AmbientChatterTopicIDs> GetAmbientChatterTopicIDFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetActivityTypeIDNameFromID(TEnumAsByte<ActivityTypeIDs> inID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<ActivityTypeIDs> GetActivityTypeIDFromName(const FName& strName);
    
};

