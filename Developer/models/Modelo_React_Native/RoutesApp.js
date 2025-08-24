import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";

import Home from "./src/pages/Home";

const Paginas = createBottomTabNavigator();

export default function RoutesApp() {
  return (
    <Paginas.Navigator>
      <Paginas.Screen name="Home" component={Home} />
    </Paginas.Navigator>
  );
}
