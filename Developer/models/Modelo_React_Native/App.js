import { StatusBar } from "expo-status-bar";
import { NavigationContainer } from "@react-navigation/native";

import RoutesApp from "./RoutesApp";

export default function App() {
  return (
    <NavigationContainer>
      <RoutesApp />
    </NavigationContainer>
  );
}
